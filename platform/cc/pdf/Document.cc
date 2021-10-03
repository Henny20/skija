#include "SkCanvas.h"
#include "SkRect.h"
#include "SkStream.h"
#include "include/docs/SkPDFDocument.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <jni.h>

class Document {
public:
  Document() {}
  Document(sk_sp<SkDocument> document) 
      : document_(document) {}
  SkCanvas *startPage(SkScalar wi, SkScalar he) {
    return document_->beginPage(wi, he);
  }
  sk_sp<SkDocument> create(SkWStream *stream) {
    document_ = SkPDF::MakeDocument(stream);
    return document_;
  }
  void endPage() { document_->endPage(); }
  void close() { document_->close(); }

private:
  ~Document() { }

  SkScalar width_;
  SkScalar height_;
  sk_sp<SkDocument> document_;
};

extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_Document__1nMake(JNIEnv *env, jclass jclass,
                                              jlong wstreamPtr,
                                              jlong metadataPtr) {

  SkWStream *wstream =
      reinterpret_cast<SkWStream *>(static_cast<uintptr_t>(wstreamPtr));

  const SkPDF::Metadata *metadata =
      reinterpret_cast<SkPDF::Metadata *>(static_cast<uintptr_t>(metadataPtr));
  
  // auto document = new Document(nullptr);
  // auto document = new Document();
  // sk_sp<SkDocument> doc = document->create(wstream);

  sk_sp<SkDocument> doc = SkPDF::MakeDocument(wstream, *metadata);

  return reinterpret_cast<jlong>(new Document(doc));
}

extern "C" JNIEXPORT jlong JNICALL
Java_org_jetbrains_skija_pdf_Document__1nBeginPage(JNIEnv *env, jclass jclass,
                                                   jlong ptr, jfloat width,
                                                   jfloat height) {

  Document *instance = reinterpret_cast<Document *>(ptr);

  SkCanvas *canvas = instance->startPage(width, height);
  
  return reinterpret_cast<jlong>(canvas);
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Document__1nEndPage(JNIEnv *env, jclass jclass,
                                                 jlong ptr) {

  Document *instance = reinterpret_cast<Document *>(ptr);
  instance->endPage();
}

extern "C" JNIEXPORT void JNICALL
Java_org_jetbrains_skija_pdf_Document__1nClose(JNIEnv *env, jclass jclass,
                                               jlong ptr) {
  Document *instance =
      reinterpret_cast<Document *>(static_cast<uintptr_t>(ptr));
  instance->close();
}
