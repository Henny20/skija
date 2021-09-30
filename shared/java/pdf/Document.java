package org.jetbrains.skija.pdf;

import java.lang.ref.*;
import org.jetbrains.skija.Canvas;
import org.jetbrains.skija.Rect;
import org.jetbrains.skija.WStream;
import org.jetbrains.skija.impl.*;


public class Document extends Managed {
   static { Library.staticLoad(); }

       
   public Document(long ptr) {
          super(ptr, _FinalizerHolder.PTR);
    }
    
    public static class _FinalizerHolder {
        public static final long PTR = _nGetFinalizer();
    }
   
   public Document(WStream stream) {
        this(_nMake(Native.getPtr(stream)));
      //  Stats.onNativeCall();
    }
    
    /**   
    public Kanvas beginPage(float width, float height, float left, float top, float right, float bottom) {
       Stats.onNativeCall();
       long cPtr = _nBeginPage(_ptr, width, height, left, top, right, bottom);
       return (cPtr == 0) ? null : new Kanvas(cPtr, false);
     }
    **/
    public Canvas beginPage(float width, float height) {
        Stats.onNativeCall();
       return new Canvas(_nBeginPage(_ptr, width, height), true, this);
       // return new Kanvas(_nBeginPage(_ptr, width, height), false);
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

    public static native long _nGetFinalizer();
    
 //  public static native long _nBeginPage(long ptr, float width, float height, float left, float top, float right, float bottom);

    public static native long _nBeginPage(long ptr, float width, float height);

    public static native void _nEndPage(long ptr);

    public static native void _nClose(long ptr);
}
