/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class HelloWorld */

#ifndef _Included_HelloWorld
#define _Included_HelloWorld
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     HelloWorld
 * Method:    printCpp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloWorld_printCpp
  (JNIEnv *, jclass);

/*
 * Class:     HelloWorld
 * Method:    printStringToCpp
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_HelloWorld_printStringToCpp
  (JNIEnv *, jclass, jstring);

/*
 * Class:     HelloWorld
 * Method:    callJavaMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloWorld_callJavaMethod
  (JNIEnv *, jobject);

/*
 * Class:     HelloWorld
 * Method:    toString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloWorld_toString
  (JNIEnv *, jobject);

/*
 * Class:     HelloWorld
 * Method:    stringFromCpp
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloWorld_stringFromCpp
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
