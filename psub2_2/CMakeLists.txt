cmake_minimum_required(VERSION 3.16)
project(psub2_2)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)

# Publisher 실행 파일 생성
add_executable(pub src/pub.cpp src/pmain.cpp)
ament_target_dependencies(pub rclcpp geometry_msgs)

# Subscriber 실행 파일 생성
add_executable(sub src/sub.cpp src/smain.cpp)
ament_target_dependencies(sub rclcpp geometry_msgs)

# ROS2에서 실행할 수 있도록 설치
install(TARGETS
  pub
  sub
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
