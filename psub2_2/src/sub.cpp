#include "psub2_2/sub.hpp"

// 메시지를 수신했을 때 실행되는 콜백함수
void Sub::subscribe_msg(
    const geometry_msgs::msg::Vector3::SharedPtr msg) const
{
    RCLCPP_INFO(
        this->get_logger(),
        "Received message: x=%.1f, y=%.1f, z=%.1f",
        msg->x, msg->y, msg->z);
}

// Subscriber 클래스 생성자
Sub::Sub() : Node("mysub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    sub_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "mytopic",
        qos_profile,
        std::bind(&Sub::subscribe_msg, this, _1));
}
