# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.1
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

"""
IDA Plugin SDK API wrapper: problems
"""

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _ida_problems
else:
    import _ida_problems

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """
    Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass
    """
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """
    Meta class to enforce nondynamic attributes (no new attributes) for a class
    """
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


import weakref

SWIG_PYTHON_LEGACY_BOOL = _ida_problems.SWIG_PYTHON_LEGACY_BOOL

import ida_idaapi


import sys
_BC695 = sys.modules["__main__"].IDAPYTHON_COMPAT_695_API

if _BC695:






    def bc695redef(func):
        ida_idaapi._BC695.replace_fun(func)
        return func


def get_problem_desc(*args) -> "qstring *":
    r"""


    Get the human-friendly description of the problem, if one was provided
    to remember_problem.
    
    get_problem_desc(t, ea) -> str
        @param t: problem list type. (C++: problist_id_t)
        @param ea: linear address. (C++: ea_t)
        @return: the message length or -1 if none
    """
    return _ida_problems.get_problem_desc(*args)

def remember_problem(*args) -> "void":
    r"""


    Insert an address to a list of problems. Display a message saying
    about the problem (except of 'PR_ATTN' , 'PR_FINAL' ) 'PR_JUMP' is
    temporarily ignored.
    
    remember_problem(type, ea, msg=None)
        @param type: problem list type (C++: problist_id_t)
        @param ea: linear address (C++: ea_t)
        @param msg: a user-friendly message to be displayed instead of the
                    default more generic one associated with the type of
                    problem. Defaults to NULL. (C++: const char *)
    """
    return _ida_problems.remember_problem(*args)

def get_problem(*args) -> "ea_t":
    r"""


    Get an address from the specified problem list. The address is not
    removed from the list.
    
    get_problem(type, lowea) -> ea_t
        @param type: problem list type (C++: problist_id_t)
        @param lowea: the returned address will be higher or equal than the
                      specified address (C++: ea_t)
        @return: linear address or  BADADDR
    """
    return _ida_problems.get_problem(*args)

def forget_problem(*args) -> "bool":
    r"""


    Remove an address from a problem list
    
    forget_problem(type, ea) -> bool
        @param type: problem list type (C++: problist_id_t)
        @param ea: linear address (C++: ea_t)
        @return: success
    """
    return _ida_problems.forget_problem(*args)

def get_problem_name(*args) -> "char const *":
    r"""


    Get problem list description.
    
    get_problem_name(type, longname=True) -> char const *
        @param type (C++: problist_id_t)
        @param longname (C++: bool)
    """
    return _ida_problems.get_problem_name(*args)

def is_problem_present(*args) -> "bool":
    r"""


    Check if the specified address is present in the problem list.
    
    is_problem_present(t, ea) -> bool
        @param t (C++: problist_id_t)
        @param ea (C++: ea_t)
    """
    return _ida_problems.is_problem_present(*args)

def was_ida_decision(*args) -> "bool":
    r"""


    was_ida_decision(ea) -> bool
        @param ea (C++: ea_t)
    """
    return _ida_problems.was_ida_decision(*args)

if _BC695:
    import sys
    sys.modules["ida_queue"] = sys.modules["ida_problems"]
    Q_Qnum=_ida_problems.cvar.PR_END
    Q_att=_ida_problems.cvar.PR_ATTN
    Q_badstack=_ida_problems.cvar.PR_BADSTACK
    Q_collsn=_ida_problems.cvar.PR_COLLISION
    Q_decimp=_ida_problems.cvar.PR_DECIMP
    Q_disasm=_ida_problems.cvar.PR_DISASM
    Q_final=_ida_problems.cvar.PR_FINAL
    Q_head=_ida_problems.cvar.PR_HEAD
    Q_jumps=_ida_problems.cvar.PR_JUMP
    Q_lines=_ida_problems.cvar.PR_MANYLINES
    Q_noBase=_ida_problems.cvar.PR_NOBASE
    Q_noComm=_ida_problems.cvar.PR_NOCMT
    Q_noFop=_ida_problems.cvar.PR_NOFOP
    Q_noName=_ida_problems.cvar.PR_NONAME
    Q_noRef=_ida_problems.cvar.PR_NOXREFS
    Q_noValid=_ida_problems.cvar.PR_ILLADDR
    Q_rolled=_ida_problems.cvar.PR_ROLLED
    QueueDel=forget_problem
    QueueGetMessage=get_problem_desc
    QueueGetType=get_problem
    QueueIsPresent=is_problem_present
    QueueSet=remember_problem
    def get_long_queue_name(t):
        return get_problem_name(t, True)
    def get_short_queue_name(t):
        return get_problem_name(t, False)



cvar = _ida_problems.cvar
PR_NOBASE = cvar.PR_NOBASE
PR_NONAME = cvar.PR_NONAME
PR_NOFOP = cvar.PR_NOFOP
PR_NOCMT = cvar.PR_NOCMT
PR_NOXREFS = cvar.PR_NOXREFS
PR_JUMP = cvar.PR_JUMP
PR_DISASM = cvar.PR_DISASM
PR_HEAD = cvar.PR_HEAD
PR_ILLADDR = cvar.PR_ILLADDR
PR_MANYLINES = cvar.PR_MANYLINES
PR_BADSTACK = cvar.PR_BADSTACK
PR_ATTN = cvar.PR_ATTN
PR_FINAL = cvar.PR_FINAL
PR_ROLLED = cvar.PR_ROLLED
PR_COLLISION = cvar.PR_COLLISION
PR_DECIMP = cvar.PR_DECIMP
PR_END = cvar.PR_END
