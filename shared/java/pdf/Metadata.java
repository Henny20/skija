package org.jetbrains.skija.pdf;

import org.jetbrains.skija.impl.*;

public class Metadata extends Native {

    public Metadata(long ptr) {
        super(ptr);
    }

    public Metadata() {
        this(_nMake());
    }

    public void setTitle(String text) {
        _nSetTitle(_ptr, text);
    }

    public void setAuthor(String text) {
        _nSetAuthor(_ptr, text);
    }

    public void setSubject(String text) {
        _nSetSubject(_ptr, text);
    }

    public void setKeywords(String text) {
        _nSetKeywords(_ptr, text);
    }

    public void setCreator(String text) {
        _nSetCreator(_ptr, text);
    }

    public void setProducer(String text) {
        _nSetProducer(_ptr, text);
    }

    public void setCreation(int timeZoneMinutes, int year, int month, int dayOfWeek, int day, int hour, int minute, int second) {
        _nSetCreation(_ptr, timeZoneMinutes, year, month, dayOfWeek, day, hour, minute, second);
    }

    public void setModified(int timeZoneMinutes, int year, int month, int dayOfWeek, int day, int hour, int minute, int second) {
        _nSetModified(_ptr, timeZoneMinutes, year, month, dayOfWeek, day, hour, minute, second);
    }

    //public void setModified(Time.DateTime value) {
    //   _nSetModified(_ptr, Time.DateTime.getCPtr(value))    
    //}


    public static native long _nMake();

    public static native void _nSetTitle(long ptr, String text);

    public final static native long _nGetTitle(long jarg1, Metadata jarg1_);

    public final static native void _nSetAuthor(long jarg1, String text);

    public final static native long _nGetAuthor(long jarg1, Metadata jarg1_);

    public final static native void _nSetSubject(long jarg1, String text);

    public final static native long _nGetSubject(long jarg1, Metadata jarg1_);

    public final static native void _nSetKeywords(long jarg1, String text);

    public final static native long _nGetKeywords(long jarg1, Metadata jarg1_);

    public final static native void _nSetCreator(long jarg1, String text);

    public final static native long _nGetCreator(long jarg1, Metadata jarg1_);

    public final static native void _nSetProducer(long jarg1, String text);

    public final static native long _nGetProducer(long jarg1, Metadata jarg1_);

    public final static native void _nSetCreation(long jarg1, int tmz, int year, int month, int dayOfWeek, int day, int hour, int minute, int second);

    public final static native long _nGetCreation(long jarg1, Metadata jarg1_);

    //public final static native void _nSetModified(long jarg1, long jarg2);

    public final static native void _nSetModified(long jarg1, int tmz, int year, int month, int dayOfWeek, int day, int hour, int minute, int second);

    public final static native long _nGetModified(long jarg1, Metadata jarg1_);

    public final static native void _nSetRasterDPI(long jarg1, float jarg2);

    public final static native float _nGetRasterDPI(long jarg1, Metadata jarg1_);

    public final static native void _nSetPDFA(long jarg1, boolean jarg2);

    public final static native boolean _nGetPDFA(long jarg1, Metadata jarg1_);

    public final static native void _nSetEncodingQuality(long jarg1, int jarg2);

    public final static native int _nGetEncodingQuality(long jarg1, Metadata jarg1_);
}  
