#include "MdfTimestamp.h"

namespace MdfLibrary {
MdfUtcTimestamp::MdfUtcTimestamp(uint64_t utc_timestamp) {
  utc_timestamp_ = utc_timestamp;
}

uint64_t MdfUtcTimestamp::UtcTimestamp::get() {
  return utc_timestamp_;
}

MdfLocalTimestamp::MdfLocalTimestamp(uint64_t local_timestamp) {
  local_timestamp_ = local_timestamp;
}

uint64_t MdfLocalTimestamp::LocalTimestamp::get() {
  return local_timestamp_;
}


MdfTimezoneTimestamp::MdfTimezoneTimestamp(uint64_t utc_timestamp,
                                           int16_t timezone_offset_min,
                                           int16_t dst_offset_min) {
  utc_timestamp_ = utc_timestamp;
  timezone_offset_min_ = timezone_offset_min;
  dst_offset_min_ = dst_offset_min;
}

uint64_t MdfTimezoneTimestamp::UtcTimestamp::get() {
  return utc_timestamp_;
}

int16_t MdfTimezoneTimestamp::TimezoneOffsetMin::get() {
  return timezone_offset_min_;
}

int16_t MdfTimezoneTimestamp::DstOffsetMin::get() {
  return dst_offset_min_;
}
}
