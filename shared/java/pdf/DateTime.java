package org.jetbrains.skija.pdf;

import org.jetbrains.skija.impl.*;

public class DateTime extends Native {

    public DateTime(long ptr) {
        super(ptr);
    }
    
   	public DateTime() {
   		this(_nMake());
    }
      
   	public DateTime makeDateTime(int timeZoneMinutes, int year, int month, int dayOfWeek, int day, int hour, int minute, int second ) {
   	    return new DateTime(_nMakeDateTime(_ptr, timeZoneMinutes, year, month, dayOfWeek, day, hour, minute, second));
    }
    
    public static native long _nMake();
    public static native long _nMakeDateTime(long ptr, int tzm, int year, int month, int dayOfWeek, int day, int hour, int minute, int second);
}
