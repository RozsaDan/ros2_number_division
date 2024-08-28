# number_division

This ROS2 node subscribes to the /inut_numbers topic, reads two float numbers, performs a division with them, and publishes the result to the '/division_rersult' topic.

##Instructions to build, run, and test the node
1. First clone the provided repository to the source code folder of your ROS2 workspace.
```
  https://github.com/RozsaDan/number_division.git
```

2. After the download, build the workspace. For this use the command below from the root of the workspace directory.
```
colcon build
```

3. Source the workspace.
```
. install/setup.bash
```

4. Now the node can be run.
```
ros2 run divide_numbers divide_numbers
```

5. To be able to test the code, there has to be a topic that propagates the corresponding data. For this a simple command from the command line is sufficient.
```
ros2 topic pub /input_numbers std_msgs/msg/Float64MultiArray "{data: [10.0, 2.0]}"
```

6. To see the result of the division, subscribe to the '/division_result' topic:
```
ros2 topic echo /division_result
```
