cmake_minimum_required(VERSION 3.8)
project(cpp_subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies using 'find_package(<dependency> REQUIRED)'
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


# Add executable 'listener' such that the minimal_subscriber node can run using 'ros2 run' command
add_executable(listener_node src/subscriber_member_function.cpp)
ament_target_dependencies(listener_node rclcpp std_msgs)


# Add install section such that 'ros2 run' can find the executable
install(TARGETS
  listener_node
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
