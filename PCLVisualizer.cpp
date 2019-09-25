// PCLVisualizer.cpp

#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

// function prototypes
pcl::PointCloud<pcl::PointXYZRGB>::Ptr makeElipse();

int main(void)
{
  std::cout << "\n\n" << "starting program" << "\n\n";

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = makeElipse();

  pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer);
  viewer->addPointCloud(cloud, "sample cloud"); // @suppress("Invalid arguments")
  viewer->addCoordinateSystem(1.0);
  viewer->spin();

  std::cout << "\n\n" << "program complete" << "\n\n";

  return (0);
}

pcl::PointCloud<pcl::PointXYZRGB>::Ptr makeElipse()
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);       // this will be the return value

  // we're going to make a cylinder along the z-axis, the color will gradually fade from red to blue

  uint8_t red = 255;
  uint8_t green = 0;
  uint8_t blue = 0;

  float radius = 1.0;

  // iterate along the z-axis
  for (float z = -2.0; z <= 2.0; z += 0.1)
  { // for each point along the Z-axis, compute an x-y circle around that z-axis point
    for (float angle = 0.0; angle <= 360.0; angle += 2.5)
    {
      // declare a point
      pcl::PointXYZRGB point;

      // compute x and y for a cicrle around point z
      point.x = radius * cosf(pcl::deg2rad(angle));
      point.y = radius * sinf(pcl::deg2rad(angle));

      // we're already outer-loop iterating on z, so point z is simply z
      point.z = z;

      // assign the point's red, green, and blue values
      point.r = red;
      point.g = green;
      point.b = blue;

      // add the point to the cloud
      cloud->points.push_back(point);
    }

    // update red and blue for the next time around
    // colors go into unsigned 8-bit integers in PCL, so we have to be careful about overflow
    // first, compute the new red and blue via decrementing/incrementing
    int newRed = red - 7;
    int newBlue = blue + 7;
    // if they overflowed and 8-bit int, knock them back to the proper values
    if (newRed < 0) newRed = 0;
    if (newBlue > 255) newBlue = 255;
    // now update red and blue with the proper values
    red = newRed;
    blue = newBlue;
  }

  // for simplicity, use and unorganized cloud, i.e. width = num points, height = 1
  cloud->width = (int) cloud->points.size();
  cloud->height = 1;

  return (cloud);
}
















