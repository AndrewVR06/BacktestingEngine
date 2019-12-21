import ctypes


class Project(object):

    _library = None
    _handle = None

    def __init__(self, project, library):
        self._handle = project
        self._library = library

