// CloudViewer.cpp

#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>


int main(void)
{
  std::cout << "\n\n" << "starting program" << "\n\n";

  // instantiate a cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  // read cloud from file
  std::string pcdFileName = "my_cloud.pcd";
  int loadPcdFileResult = pcl::io::loadPCDFile<pcl::PointXYZ>(pcdFileName, *cloud);

  if (loadPcdFileResult < 0)
  {
    std::cout << "\n" << "error loading pcd file " << pcdFileName << "\n";
    return (0);
  }

  std::cout << "\n" << pcdFileName << " loaded successfully, cloud->points.size() = " << cloud->points.size() << "\n";

  // visualize cloud with CloudViewer, the more simple of the 2 cloud viewer options

  pcl::visualization::CloudViewer cloudViewer("CloudViewer");
  cloudViewer.showCloud(cloud);
  while (!cloudViewer.wasStopped()) {}

  std::cout << "\n\n" << "program complete" << "\n\n";

  return (0);
}



