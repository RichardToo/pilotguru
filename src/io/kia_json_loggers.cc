#include <io/kia_json_loggers.hpp>

namespace pilotguru {

void SteeringCommandsJsonWriter::WriteAsJsonString(
    const kia::KiaControlCommand &command, std::ostream &file_stream) {
  file_stream << "\"command\" : {";
  file_stream << "\"type\" : \"" << command.type << "\" ";
  if (command.type != kia::KiaControlCommand::RESET) {
    file_stream << ", \"value\" : " << command.value << " ";
  }
  file_stream << "}\n";
}

void SteeringAngleJsonWriter::WriteAsJsonString(const kia::SteeringAngle &data,
                                                std::ostream &file_stream) {
  file_stream << "\"angle_deci_degrees\" : " << data.angle_deci_degrees << "\n";
}

void TargetSteeringAngleStatusJsonWriter::WriteAsJsonString(
    const kia::TargetSteeringAngleStatus &data, std::ostream &file_stream) {
  file_stream << "\"is_set\": " << (data.is_set ? "true" : "false");
  if (data.is_set) {
    file_stream << ", \"angle_degrees\": " << data.angle_degrees;
  }
  file_stream << "\n";
}

} // namespace pilotguru
