// WriteCloud.cpp

#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>

int main(void)
{
  std::cout << "\n\n" << "starting program" << "\n\n";

  pcl::PointCloud<pcl::PointXYZ> cloud;

  int numPoints = 20;

  for (int i = 0; i < numPoints; i++)
  {
    pcl::PointXYZ point;

    point.x = 1024 * rand() / (RAND_MAX + 1.0f);
    point.y = 1024 * rand() / (RAND_MAX + 1.0f);
    point.z = 1024 * rand() / (RAND_MAX + 1.0f);

    cloud.points.push_back(point);
  }

  // for simplicity, use an "unorganized" cloud, "width" = num points, "height" = 1
  cloud.width = (int)cloud.points.size();
  cloud.height = 1;

  pcl::io::savePCDFileASCII("my_cloud.pcd", cloud);

  std::cout << "\n\n" << "program complete" << "\n\n";

  return (0);
}


