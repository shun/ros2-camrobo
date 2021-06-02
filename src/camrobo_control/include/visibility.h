// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CAMROBO_CONTROL__VISIBILITY_H_
#define CAMROBO_CONTROL__VISIBILITY_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__

  #ifdef __GNUC__
    #define CAMROBO_CONTROL_EXPORT __attribute__ ((dllexport))
    #define CAMROBO_CONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define CAMROBO_CONTROL_EXPORT __declspec(dllexport)
    #define CAMROBO_CONTROL_IMPORT __declspec(dllimport)
  #endif

  #ifdef CAMROBO_CONTROL_DLL
    #define CAMROBO_CONTROL_PUBLIC CAMROBO_CONTROL_EXPORT
  #else
    #define CAMROBO_CONTROL_PUBLIC CAMROBO_CONTROL_IMPORT
  #endif

  #define CAMROBO_CONTROL_PUBLIC_TYPE CAMROBO_CONTROL_PUBLIC

  #define CAMROBO_CONTROL_LOCAL

#else

  #define CAMROBO_CONTROL_EXPORT __attribute__ ((visibility("default")))
  #define CAMROBO_CONTROL_IMPORT

  #if __GNUC__ >= 4
    #define CAMROBO_CONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define CAMROBO_CONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CAMROBO_CONTROL_PUBLIC
    #define CAMROBO_CONTROL_LOCAL
  #endif

  #define CAMROBO_CONTROL_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // CAMROBO_CONTROL__VISIBILITY_H_
