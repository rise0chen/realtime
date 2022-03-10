use std::path::PathBuf;
use std::{env, fs};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let dir = "./vendor/xenomai";
    let l = fs::canonicalize(&PathBuf::from(dir))?;
    let lib_dir = if env::var("CARGO_CFG_TARGET_ARCH").unwrap() == "aarch64" {
        "aarch64"
    } else {
        //"x86_64"
        return Ok(());
    };

    println!("cargo:rustc-link-lib=dylib={}", "trank");
    println!("cargo:rustc-link-lib=dylib={}", "alchemy");
    println!("cargo:rustc-link-lib=dylib={}", "copperplate");
    println!("cargo:rustc-link-lib=dylib={}", "cobalt");
    println!("cargo:rustc-link-lib=dylib={}", "modechk");
    println!("cargo:rustc-link-lib={}", "pthread");
    println!("cargo:rustc-link-lib={}", "rt");
    println!(
        "cargo:rustc-link-search=native={}/lib/{}",
        l.as_path().to_str().unwrap(),
        lib_dir
    );

    println!("cargo:rerun-if-changed={}/xenomai.c", dir);
    cc::Build::new()
        .file(format!("{}/xenomai.c", dir))
        .include(format!("{}/include", dir))
        .include(format!("{}/include/trank", dir))
        .include(format!("{}/include/cobalt", dir))
        .include(format!("{}/include/alchemy", dir))
        .define("__XENO_COMPAT__", None)
        .define("_GNU_SOURCE", None)
        .define("_REENTRANT", None)
        .define("__COBALT__", None)
        .compile("xenomai");

    Ok(())
}
