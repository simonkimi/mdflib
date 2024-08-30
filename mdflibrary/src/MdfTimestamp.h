#pragma once
#include <cstdint>

#include "mdf/itimestamp.h"

namespace MdfLibrary {
public interface class IMdfTimeStamp {
};


public ref class MdfUtcTimestamp : public IMdfTimeStamp {
public:
  explicit MdfUtcTimestamp(uint64_t utc_timestamp);
  property uint64_t UtcTimestamp { uint64_t get(); }

private:
  uint64_t utc_timestamp_;
};


public ref class MdfLocalTimestamp : public IMdfTimeStamp {
public:
  explicit MdfLocalTimestamp(uint64_t local_timestamp);
  property uint64_t LocalTimestamp { uint64_t get(); }

private:
  uint64_t local_timestamp_;
};


public ref class MdfTimezoneTimestamp : public IMdfTimeStamp {
public:
  explicit MdfTimezoneTimestamp(uint64_t utc_timestamp,
                                int16_t timezone_offset_min,
                                int16_t dst_offset_min);
  property uint64_t UtcTimestamp { uint64_t get(); }
  property int16_t TimezoneOffsetMin { int16_t get(); }
  property int16_t DstOffsetMin { int16_t get(); }

private:
  uint64_t utc_timestamp_;
  int16_t timezone_offset_min_;
  int16_t dst_offset_min_;
};
}
