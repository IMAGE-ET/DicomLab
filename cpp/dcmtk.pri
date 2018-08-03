INCLUDEPATH += c:/dev/dcmtk/build/install/include
Debug: {
        LIBS += \
                -lc:/dev/dcmtk/build/install/lib/debug/charls \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmdata \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmdsig \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmimage \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmimgle \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmjpeg \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmjpls \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmnet \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmpstat \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmqrdb \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmsr \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmtls \
                -lc:/dev/dcmtk/build/install/lib/debug/dcmwlm \
                -lc:/dev/dcmtk/build/install/lib/debug/i2d \
                -lc:/dev/dcmtk/build/install/lib/debug/ijg12 \
                -lc:/dev/dcmtk/build/install/lib/debug/ijg16 \
                -lc:/dev/dcmtk/build/install/lib/debug/ijg8 \
                -lc:/dev/dcmtk/build/install/lib/debug/oflog \
                -lc:/dev/dcmtk/build/install/lib/debug/ofstd
}
Release: {
                LIBS += \
                -lc:/dev/dcmtk/build/install/lib/release/charls \
                -lc:/dev/dcmtk/build/install/lib/release/dcmdata \
                -lc:/dev/dcmtk/build/install/lib/release/dcmdsig \
                -lc:/dev/dcmtk/build/install/lib/release/dcmimage \
                -lc:/dev/dcmtk/build/install/lib/release/dcmimgle \
                -lc:/dev/dcmtk/build/install/lib/release/dcmjpeg \
                -lc:/dev/dcmtk/build/install/lib/release/dcmjpls \
                -lc:/dev/dcmtk/build/install/lib/release/dcmnet \
                -lc:/dev/dcmtk/build/install/lib/release/dcmpstat \
                -lc:/dev/dcmtk/build/install/lib/release/dcmqrdb \
                -lc:/dev/dcmtk/build/install/lib/release/dcmsr \
                -lc:/dev/dcmtk/build/install/lib/release/dcmtls \
                -lc:/dev/dcmtk/build/install/lib/release/dcmwlm \
                -lc:/dev/dcmtk/build/install/lib/release/i2d \
                -lc:/dev/dcmtk/build/install/lib/release/ijg12 \
                -lc:/dev/dcmtk/build/install/lib/release/ijg16 \
                -lc:/dev/dcmtk/build/install/lib/release/ijg8 \
                -lc:/dev/dcmtk/build/install/lib/release/oflog \
                -lc:/dev/dcmtk/build/install/lib/release/ofstd
}
