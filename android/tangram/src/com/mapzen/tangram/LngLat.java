package com.mapzen.tangram;

public class LngLat {

    public double longitude; // Degrees longitude
    public double latitude;  // Degrees latitude

    public LngLat() {
        this(0, 0);
    }

    public LngLat(LngLat other) {
        set(other);
    }

    public LngLat(double lng, double lat) {
        set(lng, lat);
    }

    public LngLat set(double lng, double lat) {
        longitude = lng;
        latitude = lat;
        return this;
    }

    public LngLat set(LngLat other) {
        set(other.longitude, other.latitude);
        return this;
    }

}