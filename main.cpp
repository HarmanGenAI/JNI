#include "/Users/adolase/Downloads/JNIWrapper/JavaClass.h"
#include "/Users/adolase/Downloads/JNIWrapper/JavaObject.h"
#include "/Users/adolase/Downloads/JNIWrapper/JniWrapper.h"

int main() {
    // Initialize the JNI environment
    JavaVM* jvm;
    JNIEnv* env;
    jint result = JNI_CreateJavaVM(&jvm, (void**)&env, NULL);
    if (result != JNI_OK) {
        return -1;
    }

    // Create a JniWrapper object
    JniWrapper jniWrapper(jvm, env);

    // Load the Java class
    CJavaClass javaClass(env, "com/example/MyClass");

    // Create a Java object
    CJavaObject javaObject(env, javaClass.GetClass());

    // Call the Java method
    javaObject.GetMethod("myMethod", "()V").CallVoid();

    // Get the value of a Java field
    int myField = javaObject.GetField("myField", "I").Get<int>();

    // Set the value of a Java static field
    javaClass.GetStaticField("myStaticField", "I").Set<int>(42);

    // Call the Java static method
    javaClass.GetStaticMethod("myStaticMethod", "()V").CallVoid();

    // Get the value of a Java static field
    int myStaticField = javaClass.GetStaticField("myStaticField", "I").Get<int>();

    // Clean up
    jvm->DestroyJavaVM();

    return 0;
}