#include "MdfTimestamp.h"

namespace MdfLibrary {
MdfUtcTimestamp::MdfUtcTimestamp(const uint64_t utc_timestamp) {
  utc_timestamp_ = utc_timestamp;
}

mdf::ITimestamp* MdfUtcTimestamp::GetTimestamp() {
  return new mdf::UtcTimestamp(utc_timestamp_);
}

MdfLocalTimestamp::MdfLocalTimestamp(const uint64_t local_timestamp) {
  local_timestamp_ = local_timestamp;
}

mdf::ITimestamp* MdfLocalTimestamp::GetTimestamp() {
  return new mdf::LocalTimestamp(local_timestamp_);
}

MdfTimezoneTimestamp::MdfTimezoneTimestamp(const uint64_t utc_timestamp,
                                           const int16_t timezone_offset_min,
                                           const int16_t dst_offset_min) {
  utc_timestamp_ = utc_timestamp;
  timezone_offset_min_ = timezone_offset_min;
  dst_offset_min_ = dst_offset_min;
}

mdf::ITimestamp* MdfTimezoneTimestamp::GetTimestamp() {
  return new mdf::TimezoneTimestamp(utc_timestamp_, timezone_offset_min_,
                                    dst_offset_min_);
}
}
