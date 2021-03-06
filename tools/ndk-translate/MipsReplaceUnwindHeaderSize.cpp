/*
 * Copyright 2013, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ReplaceUnwindHeaderSizePass.h"

class MipsReplaceUnwindHeaderSize : public ReplaceUnwindHeaderSizePass {
public:
  virtual const char *getPassName() const {
    return "Mips LLVM Unwind Header Size Replacement Pass";
  }

  virtual size_t getTargetUnwindHeaderSize() const {
    return 24;  // sizeof(_Unwind_Exception) == 24 on MIPS
  }
};

ReplaceUnwindHeaderSizePass* createMipsReplaceUnwindHeaderSizePass() {
  return new MipsReplaceUnwindHeaderSize();
}

