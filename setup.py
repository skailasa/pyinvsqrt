import os

from setuptools import setup, find_packages
from setuptools.extension import Extension

HERE = os.path.abspath(os.path.dirname(__file__))
PATH_VERSION = os.path.join(HERE, 'pyinvsqrt', '__version__.py')

ABOUT = {}

with open(PATH_VERSION, mode='r', encoding='utf-8') as f:
    exec(f.read(), ABOUT)

requirements = [
    'numpy',
    'pytest'
]


c_module = Extension(
    'invsqrtc',
    sources=['pyinvsqrt/main.c'],
    include_dirs=['/usr/local/lib']
)


setup(
    name=ABOUT['__title__'],
    version=ABOUT['__version__'],
    description=ABOUT['__description__'],
    packages=find_packages(),
    ext_modules=[c_module],
    license="BSD",
    author="Srinath Kailasa",
    author_email='srinathkailasa@gmail.com',
    url='https://github.com/skailasa/pyinvsqrt',
    zip_safe=False,
    install_requires=requirements,
    keywords='InvSqrRoot',
    classifiers=[
        'Programming Language :: Python :: 3.8',
    ]
)
