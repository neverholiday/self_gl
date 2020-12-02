# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.12
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info >= (2, 7, 0):
    def swig_import_helper():
        import importlib
        pkg = __name__.rpartition('.')[0]
        mname = '.'.join((pkg, '_MyMath')).lstrip('.')
        try:
            return importlib.import_module(mname)
        except ImportError:
            return importlib.import_module('_MyMath')
    _MyMath = swig_import_helper()
    del swig_import_helper
elif _swig_python_version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_MyMath', [dirname(__file__)])
        except ImportError:
            import _MyMath
            return _MyMath
        try:
            _mod = imp.load_module('_MyMath', fp, pathname, description)
        finally:
            if fp is not None:
                fp.close()
        return _mod
    _MyMath = swig_import_helper()
    del swig_import_helper
else:
    import _MyMath
del _swig_python_version_info

try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        if _newclass:
            object.__setattr__(self, name, value)
        else:
            self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr(self, class_type, name):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    raise AttributeError("'%s' object has no attribute '%s'" % (class_type.__name__, name))


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except __builtin__.Exception:
    class _object:
        pass
    _newclass = 0

class Matrix4(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Matrix4, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Matrix4, name)
    __repr__ = _swig_repr

    def __init__(self):
        this = _MyMath.new_Matrix4()
        try:
            self.this.append(this)
        except __builtin__.Exception:
            self.this = this
    __swig_destroy__ = _MyMath.delete_Matrix4
    __del__ = lambda self: None

    def setValue(self, *args):
        return _MyMath.Matrix4_setValue(self, *args)

    def getValue(self, *args):
        return _MyMath.Matrix4_getValue(self, *args)

    def getNumRow(self):
        return _MyMath.Matrix4_getNumRow(self)

    def getNumColumn(self):
        return _MyMath.Matrix4_getNumColumn(self)

    def getData(self):
        return _MyMath.Matrix4_getData(self)

    def setZero(self):
        return _MyMath.Matrix4_setZero(self)

    def identity(self):
        return _MyMath.Matrix4_identity(self)

    def add(self, other):
        return _MyMath.Matrix4_add(self, other)

    def printMatrix(self):
        return _MyMath.Matrix4_printMatrix(self)

    def __repr__(self):
        reprString = ''
        for i in range( self.getNumRow() ):
            for j in range( self.getNumColumn() ):
                idx = self.getNumColumn() * i + j;
                reprString += '{} '.format( self.getValue(idx) )
            reprString += '\n'
        return reprString

Matrix4_swigregister = _MyMath.Matrix4_swigregister
Matrix4_swigregister(Matrix4)

# This file is compatible with both classic and new-style classes.

