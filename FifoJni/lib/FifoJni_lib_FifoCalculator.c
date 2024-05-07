#include <jni.h>

/*
 * Class:     FifoJni_lib_FifoCalculator
 * Method:    fifo
 * Signature: ([CI)[C
 */
JNIEXPORT jcharArray JNICALL Java_FifoJni_lib_FifoCalculator_fifo
  (JNIEnv * env , jobject obj, jcharArray texto, jint size){
jsize len = (*env)->GetArrayLength(env, texto);
    jchar *cadena = (*env)->GetCharArrayElements(env, texto, NULL);

    jint max = (int)len;
    jint head = -1;
    jint indicador = 0;
    jint marcos = 3;
    jchar cola[marcos];
    jchar resultado[max * marcos];
    jint pos = 0;

    for (jint i = 0; i < max; i++) {
        if (head < marcos - 1) {
            head++;
        } else {
            head = 0;
        }

        indicador = 0;


        for (jint j = 0; j < marcos; j++) {
            if (cola[j] == cadena[i]) {
                indicador = 1;
            }
        }

        if (indicador == 0) {
            cola[head] = cadena[i];
        }

        for (jint x = 0; x < marcos; x++) {
            resultado[pos++] = cola[x];
        }
    }

    jcharArray resultadoArray = (*env)->NewCharArray(env, max * marcos);
    (*env)->SetCharArrayRegion(env, resultadoArray, 0, max * marcos, resultado);

    (*env)->ReleaseCharArrayElements(env, texto, cadena, JNI_ABORT);

    return resultadoArray;


}
