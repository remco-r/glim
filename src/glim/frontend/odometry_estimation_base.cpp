#include <glim/frontend/odometry_estimation_base.hpp>

#include <glim/frontend/callbacks.hpp>

namespace glim {

using Callbacks = OdometryEstimationCallbacks;

void OdometryEstimationBase::insert_image(const double stamp, const cv::Mat& image) {
  Callbacks::on_insert_image(stamp, image);
}

void OdometryEstimationBase::insert_imu(const double stamp, const Eigen::Vector3d& linear_acc, const Eigen::Vector3d& angular_vel) {
  Callbacks::on_insert_imu(stamp, linear_acc, angular_vel);
}

EstimationFrame::ConstPtr OdometryEstimationBase::insert_frame(const PreprocessedFrame::Ptr& frame, std::vector<EstimationFrame::ConstPtr>& marginalized_states) {
  Callbacks::on_insert_frame(frame);
  return nullptr;
}
}