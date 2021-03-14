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
     float number;

     /*Parse the Python argument into a single*/
    if (!PyArg_ParseTuple(args, "f", &number)) {
        return NULL;
    }

    /*Logic*/
    //x = 1/sqrtf(x);

	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed


    /*Build answer back into a Python object*/
    return Py_BuildValue("f", y);
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
