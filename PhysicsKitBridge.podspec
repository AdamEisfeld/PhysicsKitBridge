#
# Be sure to run `pod lib lint PhysicsKitBridge.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PhysicsKitBridge'
  s.version          = '0.1.0'
  s.summary          = 'A short description of PhysicsKitBridge.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/AdamEisfeld/PhysicsKitBridge'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'AdamEisfeld' => 'adam.eisfeld@gmail.com' }
  s.source           = { :git => 'https://github.com/AdamEisfeld/PhysicsKitBridge.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'

  s.library = 'c++'

  s.preserve_paths = 'PhysicsKitBridge/Source/**'
  s.source_files = 'PhysicsKitBridge/Source/bulletLib/src/**/*.{h,m,mm,cpp}', 'PhysicsKitBridge/Source/bulletLib/Extras/Serialize/BulletWorldImporter/**/*.{h,m,mm,cpp}', 'PhysicsKitBridge/Source/bulletLib/Extras/Serialize/BulletFileLoader/**/*.{h,m,mm,cpp}', 'PhysicsKitBridge/Source/Internal/**/*.{h,m,mm,cpp}'
  s.exclude_files = 'PhysicsKitBridge/Source/bulletLib/src/Bullet3OpenCL'

  s.static_framework = true

  s.xcconfig = {
    'USE_HEADERMAP' => 'NO',
    'HEADER_SEARCH_PATHS' => '$(SRCROOT)/../../**',
    'USER_HEADER_SEARCH_PATHS' => '$(SRCROOT)/../../**',
    'CLANG_CXX_LANGUAGE_STANDARD' => 'c++11',
    'CLANG_CXX_LIBRARY' => 'libc++',
  }
  s.pod_target_xcconfig = {
    'HEADER_SEARCH_PATHS' => '$(SRCROOT)/../../**'
  }

end
