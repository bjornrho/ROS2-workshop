// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "custom_interfaces_final/msg/custom_message.hpp"

using std::placeholders::_1;

class MinimalCPPSubscriber : public rclcpp::Node
{
public:
  MinimalCPPSubscriber()
  : Node("minimal_cpp_subscriber")
  {
    subscription_ = this->create_subscription<custom_interfaces_final::msg::CustomMessage>(
      "the_ultimate_topic", 10, std::bind(&MinimalCPPSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const custom_interfaces_final::msg::CustomMessage::ConstSharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard: '%s' and '%li'", msg->complementary_message.c_str(), msg->current_message_iteration);
  }
  rclcpp::Subscription<custom_interfaces_final::msg::CustomMessage>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalCPPSubscriber>());
  rclcpp::shutdown();
  return 0;
}
