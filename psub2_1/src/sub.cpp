#include "psub2_1/sub.hpp"

// 메시지를 수신했을 때 실행되는 콜백함수
void Sub::subscribe_msg(
    const std_msgs::msg::Int32::SharedPtr msg) const
{
    RCLCPP_INFO(
        this->get_logger(),
        "Received message: %d",
        msg->data);
}

// Subscriber 클래스 생성자
Sub::Sub() : Node("mysub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    sub_ = this->create_subscription<std_msgs::msg::Int32>(
        "mytopic",
        qos_profile,
        std::bind(&Sub::subscribe_msg, this, _1));
}
