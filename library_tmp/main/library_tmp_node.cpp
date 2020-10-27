#include "library_tmp/library_tmp.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "library_tmp");
  //ノード名の初期化

  LibraryTmp a;

  ros::spin();

  return 0;
}