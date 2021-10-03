#include "../interop.hh"
#include "include/docs/SkPDFDocument.h"
#include <iostream>
#include <jni.h>

extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nMake(JNIEnv *env, jclass jclass) {

  return reinterpret_cast<jlong>(new SkPDF::Metadata());
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetTitle(JNIEnv *env, jclass jclass,
                                                  jlong ptr, jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fTitle = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetAuthor(JNIEnv *env, jclass jclass,
                                                   jlong ptr, jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fAuthor = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetSubject(JNIEnv *env, jclass jclass,
                                                    jlong ptr,
                                                    jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fSubject = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetKeywords(JNIEnv *env, jclass jclass,
                                                     jlong ptr,
                                                     jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fKeywords = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetCreator(JNIEnv *env, jclass jclass,
                                                    jlong ptr,
                                                    jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fCreator = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetProducer(JNIEnv *env, jclass jclass,
                                                     jlong ptr,
                                                     jstring textObj) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));
  SkString text = skString(env, textObj);
  if (metadata)
    (metadata)->fProducer = text.c_str();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetCreation(
    JNIEnv *env, jclass jclass, jlong ptr, jint tmz, jint year, jint month,
    jint dayOfWeek, jint day, jint hour, jint minute, jint second) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));

  if (metadata)
    (metadata)->fCreation = {(int16_t)tmz,       (uint16_t)year, (uint8_t)month,
                             (uint8_t)dayOfWeek, (uint8_t)day,   (uint8_t)hour,
                             (uint8_t)minute,    (uint8_t)second};
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Metadata__1nSetModified(
    JNIEnv *env, jclass jclass, jlong ptr, jint tmz, jint year, jint month,
    jint dayOfWeek, jint day, jint hour, jint minute, jint second) {

  SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(ptr));

  if (metadata)
    (metadata)->fModified = {(int16_t)tmz,       (uint16_t)year, (uint8_t)month,
                             (uint8_t)dayOfWeek, (uint8_t)day,   (uint8_t)hour,
                             (uint8_t)minute,    (uint8_t)second};
}
