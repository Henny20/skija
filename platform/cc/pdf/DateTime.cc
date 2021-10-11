#include "../interop.hh"
#include "SkTime.h"
#include <iostream>
#include <jni.h>
/**
extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_Time__1nMake(JNIEnv *env, jclass jclass) {

  return reinterpret_cast<jlong>(new SkTime());
}
**/
extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_DateTime__1nMake(JNIEnv *env, jclass jclass) {
  
  return reinterpret_cast<jlong>(new SkTime::DateTime());
}

extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_DateTime__1nMakeDateTime(
    JNIEnv *env, jclass jclass, jlong ptr, jint tmz, jint year, jint month,
    jint dayOfWeek, jint day, jint hour, jint minute, jint second) {

  SkTime::DateTime *arg =
      reinterpret_cast<SkTime::DateTime *>(static_cast<uintptr_t>(ptr));

  arg->fTimeZoneMinutes = (int16_t)tmz;
  arg->fYear = (uint16_t)year;
  arg->fMonth = (uint8_t)month;
  arg->fDayOfWeek = (uint8_t)dayOfWeek;
  arg->fDay = (uint8_t)day;
  arg->fHour = (uint8_t)hour;
  arg->fMinute = (uint8_t)minute;
  arg->fSecond = (uint8_t)second;

  return reinterpret_cast<jlong>(arg);
}
