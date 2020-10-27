#include "library_template/library_template.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "library_template");
  //ノード名の初期化

  LibraryTmp a;

  ros::spin();

  return 0;
}