#include "psub2_2/pub.hpp"

// Publisher 클래스 생성자
Pub::Pub() : Node("mypub"), count_(0.0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "mytopic", qos_profile);

    timer_ = this->create_wall_timer(
        1s, std::bind(&Pub::publish_msg, this));
}

// 메시지를 발행하는 멤버함수
void Pub::publish_msg()
{
    auto msg = geometry_msgs::msg::Vector3();

    msg.x = count_;
    msg.y = count_;
    msg.z = count_;

    RCLCPP_INFO(this->get_logger(),
                "Published message: x=%.1f, y=%.1f, z=%.1f",
                msg.x, msg.y, msg.z);

    pub_->publish(msg);

    count_ += 1.0;
}
