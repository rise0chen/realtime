fn main() -> Result<(), Box<dyn std::error::Error>> {
    println!("cargo:rerun-if-changed=vendor/rtai/rtai.c");
    cc::Build::new()
        .file("vendor/rtai/rtai.c")
        .include("vendor/rtai/include")
        .compile("rtai");

    Ok(())
}
