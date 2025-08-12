/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_CHROME_STRING_LOOKUP_H_
#define SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_CHROME_STRING_LOOKUP_H_

#include <array>

#include "protos/perfetto/trace/track_event/chrome_thread_descriptor.pbzero.h"
#include "protos/third_party/chromium/chrome_enums.pbzero.h"
#include "src/trace_processor/storage/trace_storage.h"

namespace perfetto {
namespace trace_processor {

class ChromeStringLookup {
 public:
  explicit ChromeStringLookup(TraceStorage* storage,
                              bool ignore_predefined_names_for_testing = false);

  StringId GetProcessName(int32_t process_type) const;
  StringId GetThreadName(int32_t thread_type) const;

 private:
  std::array<StringId,
             ::perfetto::protos::chrome_enums::pbzero::ProcessType_MAX + 1>
      chrome_process_name_ids_{};
  std::array<StringId,
             ::perfetto::protos::pbzero::ChromeThreadDescriptor_ThreadType_MAX +
                 1>
      chrome_thread_name_ids_{};
};

}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_IMPORTERS_PROTO_CHROME_STRING_LOOKUP_H_
