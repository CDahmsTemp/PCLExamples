// ReadCloud.cpp

#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>

int main(void)
{
  std::cout << "\n\n" << "starting program" << "\n\n";

  // instantiate a cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  std::string pcdFileName = "my_cloud.pcd";
  int loadPcdFileResult = pcl::io::loadPCDFile<pcl::PointXYZ>(pcdFileName, *cloud);

  if (loadPcdFileResult < 0)
  {
    std::cout << "\n" << "error loading pcd file " << pcdFileName << "\n";
    return (0);
  }

  std::cout << "\n" << pcdFileName << " loaded successfully, cloud->points.size() = " << cloud->points.size() << "\n";

  std::cout << "\n\n" << "program complete" << "\n\n";

  return (0);
}



