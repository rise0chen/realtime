use std::fs;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let asm_path = Path::new("vendor/rtai/include/asm");
    let asm_origin = "./asm-x86";
    let _ = fs::remove_file(&asm_path);
    std::os::unix::fs::symlink(asm_origin, asm_path).unwrap();

    println!("cargo:rerun-if-changed=vendor/rtai/rtai.c");
    cc::Build::new()
        .file("vendor/rtai/rtai.c")
        .include("vendor/rtai/include")
        .compile("rtai");

    Ok(())
}
