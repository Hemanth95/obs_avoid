# Obs_Avoid
Obs_Avoid is a ROS package that provides obstacle avoidance functionality for mobile robots. The package contains nodes for sensor data acquisition, obstacle detection, and motion planning.

# Installation
To use Obs_Avoid, you need to have ROS installed on your system. You can install ROS by following the instructions provided on the ROS wiki: http://wiki.ros.org/ROS/Installation.

Once you have ROS installed, you can download the Obs_Avoid package and build it using the following commands:

``` bash
cd ~/catkin_ws/src
git clone https://github.com/Hemanth95/Obs_Avoid.git
cd ..
catkin_make
```
# Usage
To use Obs_Avoid, you need to connect your mobile robot's sensors (e.g., lidar, camera) to your ROS system. You can then launch the Obs_Avoid nodes using the following command:
``` bash
roslaunch obs_avoid obs_avoid.launch
```
This will launch the sensor data acquisition and obstacle detection nodes, as well as the motion planning node. You can then control your robot using ROS commands (e.g., rosrun teleop_twist_keyboard teleop_twist_keyboard.py) and the robot will avoid obstacles in its path.

# Contributing
If you want to contribute to the Obs_Avoid project, feel free to fork the repository and make changes as needed. We welcome contributions of all types, including bug fixes, new features, or documentation improvements.

Before making any changes, please create a new branch and submit a pull request outlining the changes you made. We will review your changes and merge them into the main branch if they meet our guidelines and standards.

# License
Obs_Avoid is released under the MIT License. See the LICENSE file for more information
