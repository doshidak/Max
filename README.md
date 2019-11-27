<p align="center">
  <img width="100%" alt="readme-banner" src="https://user-images.githubusercontent.com/18254287/67452246-728b0d00-f5d7-11e9-9c05-807dc6e9c642.png">
</p>

> "Max is an application for creating high-quality audio files in various formats, from compact discs or files."  
> — [Official Website](https://sbooth.org/Max/)

This is an **unofficial version** of Max that has been recompiled to support 64-bit architectures (supported on macOS Catalina!) and features a slightly modified user interface compared to those of the official versions.

### [Download v0.9.2](https://github.com/doshidak/Max/releases/tag/release-0.9.2)

**Build:** 24  
**Requires:** macOS 10.9+  
**Released:** Wednesday, October 27, 2019

> **Disclaimer:** As previously mentioned, this is an **unofficial version** of the Max app. This version is not endorsed by Stephen F. Booth or anyone else on the original Max development team. Use at your own risk!

## Why?

Max was my go-to app to convert `wav` files to `mp3` and I loved how simple and easy it was to edit the metadata/album art and export it to various formats (I would frequently export 128/192/256/320 kbps CBR `mp3`s depending on the intended destination).

When macOS Catalina dropped, I was sad to learn Max wouldn't make the cut since it was still 32-bit (and Catalina dropped support for 32-bit entirely). I've tried alternatives, but nothing streamlined my workflow like Max did. I was hoping that it would be updated for 64-bit, but it appeared that this wasn't happening anytime soon (and people who tried didn't have much luck apparently). So I tried taking a stab at it, and well, here we are!

### Why release an unofficial version?

I wanted to make changes and add new features that would benefit my specific workflow (namely focusing more on the *conversion* side of Max, rather than the *ripping*), so I decided to release these changes under my fork as they may make other people [ＡＮＧＥＲＹ](https://knowyourmeme.com/memes/angery)*. But in case my use case is similar to yours, I'm making this publicly available for you to use!

> \* I apologize for linking to a "[normie](https://knowyourmeme.com/memes/normie)" website... oh wait.

## Does it work?

Well, *sort of*. I say this because I have only tested `wav` to `mp3` conversions (since that's all I used Max for). Any other format remains untested. I also haven't tested CD ripping (largely because I don't have a DVD drive/CDs anymore) or MusicBrainz either.

But feel free to let me know if something doesn't work; I'll try my best to fix it! For me, at least, I'm just happy to be able to use Max again :)

## What's different?

Glad you asked! Here's a list of the changes I've made so far:

### 1. Redesigned App Icon

The original Max icon, while it looks great, is unfortunately low-res (especially noticeable on Macs with Retina displays). I basically recreated a high-res version of it with some minor tweaks so it doesn't look out of place with other modern apps! (You can see what it looks like in the top banner.)

### 2. Dark Mode Support

<p align="center">
  <img width="916px" alt="readme-screenshot-00" src="https://user-images.githubusercontent.com/18254287/67465191-8ba4b580-f5f9-11e9-9ff0-9ca818daaca2.png">
</p>

Since dark mode was introduced in macOS Mojave (10.14) and this version of Max was built with the macOS Catalina (10.15) SDK and Xcode 11.1, we got dark mode! I believe there are a few graphical glitches (like white text against a white background in a text field), but I'll get around to fixing those!

### 3. Metadata Inspector

<p align="center">
  <img width="802px" alt="readme-screenshot-01" src="https://user-images.githubusercontent.com/18254287/67465573-43d25e00-f5fa-11e9-9a0a-ff2a18286a37.png">
</p>

[Apple had deprecated drawers](https://developer.apple.com/documentation/appkit/nsdrawer) (the little side panels that slid beneath the window) awhile back. So to give Max a "modern" refresh, I combined both the metadata and album art drawers into a single HUD (heads up display) window! I also tried to mimic the layout of the "Get Info" window of the Music app (formerly iTunes) as much as possible.

### ...More coming soon!

I've got some more ideas I'd like to implement, so when they're ready to go, I'll update this list.

**Got some cool ideas too?** Feel free to send them my way by [opening an issue](https://github.com/doshidak/Max/issues/new)! :)

> **Disclaimer:** My Objective-C/C++ knowledge is *super* rusty (I primarily work with JavaScript/Node.js nowadays), so I can't promise you I'll be able to implement the craziest of features... but someone else might! ;)
