from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="topic_explorer",
            node_executable="topic_explorer_node",
            node_name="topic_explorer_node",
            output="screen",
            parameters=[
            ],
        )
    ])
