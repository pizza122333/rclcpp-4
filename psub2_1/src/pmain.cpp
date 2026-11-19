#include "psub2_1/pub.hpp"

int main(int argc, char * argv[])
{
    // ROS2 초기화
    rclcpp::init(argc, argv);

    // Pub 클래스 객체 생성
    auto node = std::make_shared<Pub>();

    // 타이머 이벤트 처리
    rclcpp::spin(node);

    // ROS2 종료
    rclcpp::shutdown();

    return 0;
}
