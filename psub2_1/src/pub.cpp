#include "psub2_1/pub.hpp"

// Publisher 클래스 생성자
Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    pub_ = this->create_publisher<std_msgs::msg::Int32>(
        "mytopic", qos_profile);

    timer_ = this->create_wall_timer(
        50ms, std::bind(&Pub::publish_msg, this));
}

// 메시지를 발행하는 멤버함수
void Pub::publish_msg()
{
    auto msg = std_msgs::msg::Int32();

    msg.data = static_cast<int32_t>(count_++);

    RCLCPP_INFO(this->get_logger(),
                "Published message: %d", msg.data);

    pub_->publish(msg);
}
