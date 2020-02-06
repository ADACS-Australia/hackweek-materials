import setuptools

import versioneer

DESCRIPTION_FILES = ["README.md"] # You could add the changelog here if you wanted

long_description = []
import codecs
for filename in DESCRIPTION_FILES:
    with codecs.open(filename, 'r', 'utf-8') as f:
        long_description.append(f.read())
long_description = "\n".join(long_description)


setuptools.setup(
    # setuptools stuff for versioning
    cmdclass=versioneer.get_cmdclass(),
    version = versioneer.get_version(),
    # tell setuptools to look in src
    packages = setuptools.find_packages('src'), 
    package_dir = {'': 'src'},
    # metadata about your project
    name = "<package-name-here>",
    install_requires = [], # put any requirements here (e.g. numpy)
    python_requires = '>=3.5', # put minimum python version here
    author = "<Your Name>",
    author_email = "<Your Email>",
    description = "<short 100 char description>",
    long_description = long_description,
    license = "<license>", # you should pick an open source license
    keywords = "<keywords>", # some keywords to help find your project
    url = "", # main url of project
    project_urls={ # add specific urls
        'Documentation': '',
        'Source': '',
        'Tracker': '',
    },
    classifiers=[ ], # more metadata, see https://pypi.org/classifiers/
)
