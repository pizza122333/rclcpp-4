#include "psub2_2/sub.hpp"

int main(int argc, char * argv[])
{
    // ROS2 초기화
    rclcpp::init(argc, argv);

    // Sub 클래스 객체 생성
    auto node = std::make_shared<Sub>();

    // 메시지 수신 대기 및 콜백 실행
    rclcpp::spin(node);

    // ROS2 종료
    rclcpp::shutdown();

    return 0;
}
