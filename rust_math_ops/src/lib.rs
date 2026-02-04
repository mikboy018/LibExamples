#[no_mangle]
pub extern "C" fn rust_add(a: f64, b: f64) -> f64{
    a+b
}

#[no_mangle]
pub extern "C" fn rust_div(a: f64, b: f64) -> f64{
    let mut c = b;
    if c == 0.0 {
        c = 0.000000001
    }
    a/c
}