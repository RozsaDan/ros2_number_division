#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

using std::placeholders::_1;

class DivideNumbers : public rclcpp::Node
{
  public:
    DivideNumbers()
    : Node("divide_numbers")
    {
      publisher_ = this->create_publisher<std_msgs::msg::Float64>("division_result", 10);
      subscription_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
                      "input_numbers", 10, std::bind(&DivideNumbers::input_numbers_callback, this, _1));
    }

  private:

    void input_numbers_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
    {

      if(msg->data.size() != 2){
        RCLCPP_INFO(this->get_logger(), "Exactly two numbers were expected!");
        return;
      }

      double first_number = msg->data[0];
      double second_number = msg->data[1];

      if(second_number == 0){
        RCLCPP_INFO(this->get_logger(), "Division by 0 is not possible!");
        return;
      }

      double result = first_number / second_number;
      auto message = std_msgs::msg::Float64();
      message.data = result;
      RCLCPP_INFO(this->get_logger(), "Result: '%f'", result);
      publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DivideNumbers>());
  rclcpp::shutdown();
  return 0;
}
