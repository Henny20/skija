package org.jetbrains.skija.pdf;

import java.lang.ref.*;
import org.jetbrains.skija.Canvas;
import org.jetbrains.skija.Rect;
import org.jetbrains.skija.WStream;
import org.jetbrains.skija.impl.*;


public class Document extends Native {
      
    public Document(long ptr) {
          super(ptr);
    }
    
    public Document(WStream stream) {
        this(_nMake(Native.getPtr(stream)))
    }
    
    public Canvas beginPage(float width, float height) {
        Stats.onNativeCall();
       return new Canvas(_nBeginPage(_ptr, width, height), true, this);
    }
 
    public void endPage() {
        Stats.onNativeCall();
        _nEndPage(_ptr);
    }

    public void close() {
        Stats.onNativeCall();
        _nClose(_ptr);
    }

    public static native long _nMake(long wstreamPtr);
      
    public static native long _nBeginPage(long ptr, float width, float height);

    public static native void _nEndPage(long ptr);

    public static native void _nClose(long ptr);
}
