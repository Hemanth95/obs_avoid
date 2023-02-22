#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "scan", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 100);
    robot_stop();
    RCLCPP_INFO(this->get_logger(), "calling avoid");
    //avoid();
  }

private:
  void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
  {
    //RCLCPP_INFO(this->get_logger(), "I heard: '%f'", msg->ranges[0]);
    //int x=10;
    scan = msg;
    avoid();
  }
  void robot_stop(){
    vel.linear.x = 0.0;
    vel.linear.y = 0.0;
    vel.linear.z = 0.0;
    publisher_->publish(vel);
  }
  void avoid(){
    float left = scan->ranges[22];
    float right = scan->ranges[338];
    float front = scan->ranges[0];
    float close = 0.5;

    front = std::min(front, close);
    right = std::min(right, close);
    left = std::min(left, close);
   

    vel.linear.x = (front-0.3) - (0.5-right ) - (0.5- left);
    vel.angular.z = ((left - 0.5) * 1.5 + (0.5- right)* 1.5) + 0.2* (front -0.5);
    RCLCPP_INFO(this->get_logger(), "left  %f, front %f, right %f, linear %f, angular %f",left,front,right,vel.linear.x, vel.angular.z);
    publisher_->publish(vel);
    
  }
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
sensor_msgs::msg::LaserScan::SharedPtr scan;
geometry_msgs::msg::Twist vel;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}


#include<memory>