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

#ifndef MOTOR_CONTROL__VISIBILITY_H_
#define MOTOR_CONTROL__VISIBILITY_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__

  #ifdef __GNUC__
    #define MOTOR_CONTROL_EXPORT __attribute__ ((dllexport))
    #define MOTOR_CONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define MOTOR_CONTROL_EXPORT __declspec(dllexport)
    #define MOTOR_CONTROL_IMPORT __declspec(dllimport)
  #endif

  #ifdef MOTOR_CONTROL_DLL
    #define MOTOR_CONTROL_PUBLIC MOTOR_CONTROL_EXPORT
  #else
    #define MOTOR_CONTROL_PUBLIC MOTOR_CONTROL_IMPORT
  #endif

  #define MOTOR_CONTROL_PUBLIC_TYPE MOTOR_CONTROL_PUBLIC

  #define MOTOR_CONTROL_LOCAL

#else

  #define MOTOR_CONTROL_EXPORT __attribute__ ((visibility("default")))
  #define MOTOR_CONTROL_IMPORT

  #if __GNUC__ >= 4
    #define MOTOR_CONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define MOTOR_CONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MOTOR_CONTROL_PUBLIC
    #define MOTOR_CONTROL_LOCAL
  #endif

  #define MOTOR_CONTROL_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // MOTOR_CONTROL__VISIBILITY_H_
