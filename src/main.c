#include <Python.h>
#include <math.h>

/*
 * Numpy Ufunc for inverse square roots.
 */

/*Declare Function*/
static PyObject* main_invsqrtc(PyObject *self, PyObject *args);

/*
 * This tells Python what methods this module has.
 * See the Python-C API for more information.
 */
static PyMethodDef InvSqrtCMethods[] = {
    {"invsqrt",
        main_invsqrtc,
        METH_VARARGS, "compute inverse square root"},
    {NULL, NULL, 0, NULL}
};

/*
 * Actually define the methods
 */

 static PyObject* main_invsqrtc(PyObject *self, PyObject *args)
 {
     float x;

     /*Parse the Python argument into a single*/
    if (!PyArg_ParseTuple(args, "f", &x)) {
        return NULL;
    }

    x = 1/sqrtf(x);

    /*Build answer back into a Python object*/
    return Py_BuildValue("f", x);
 }


static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "main",
    NULL,
    -1,
    InvSqrtCMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_invsqrtc(void)
{
    PyObject *m;
    m = PyModule_Create(&moduledef);
    if (!m) {
        return NULL;
    }
    return m;
}
