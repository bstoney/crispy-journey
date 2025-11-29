plugins {
    kotlin("jvm") version "2.3.0-RC"
}

sourceSets {
    main {
        kotlin.srcDir("src/kotlin/src")
    }
    test {
        kotlin.srcDir("src/kotlin/tst")
    }
}

dependencies {
    testImplementation("org.assertj:assertj-core:3.27.6")
    testImplementation("org.junit.jupiter:junit-jupiter:6.0.1")
}

tasks {
    wrapper {
        gradleVersion = "9.2.1"
    }

    test {
        useJUnitPlatform()
    }
}

kotlin {
    jvmToolchain(25)
}