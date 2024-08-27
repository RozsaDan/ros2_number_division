# number_division
1. First download the provided package to source code folder of your ROS2 workspace. 
https://github.com/RozsaDan/number_division.git

2. After the download, build the workspace. For this use the command below from the root of the workspace directory.
colcon build

3. Source the workspace.
. install/setup.bash

4. Now the node can be run.
ros2 run divide_numbers divide_numbers

5. To be able to test the code, there has to be a topic which propagates the corresponding data. For this a simple command from the command line is sufficient.
ros2 topic pub /einput_numbers std_msgs/msg/Float64MultiArray "{layout: {dim: [], data_offset: 0}, data: [4.3, 4.6]}"
