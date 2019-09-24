// WriteCloud.cpp

#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>

int main(void)
{
  std::cout << "\n\n" << "starting program" << "\n\n";

  // instantiate a cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  // populate the cloud with 20 random points
  int numPoints = 20;
  for (int i = 0; i < numPoints; i++)
  {
    pcl::PointXYZ point;

    point.x = 1024 * rand() / (RAND_MAX + 1.0f);
    point.y = 1024 * rand() / (RAND_MAX + 1.0f);
    point.z = 1024 * rand() / (RAND_MAX + 1.0f);

    cloud->points.push_back(point);
  }

  // for simplicity, use and unorganized cloud, i.e. width = num points, height = 1
  cloud->width = (int)cloud->points.size();
  cloud->height = 1;

  // write the cloud to file
  pcl::io::savePCDFileASCII("my_cloud.pcd", *cloud);

  std::cout << "\n\n" << "program complete" << "\n\n";

  return (0);
}




